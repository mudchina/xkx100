// cmds/usr/sos.c
// Last Modified by winder on Feb. 17 2001
inherit F_CLEAN_UP;
inherit F_SAVE;


#define SOS_DIR       "/data/sos/"
#define SOS_FILENAME  "sos"

#include <ansi.h>


mapping *notes;

string query_save_file()
{
	return SOS_DIR + SOS_FILENAME ;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
	int i; //line 20
	note["msg"] = text;
	i = sizeof(notes);
	for( ; i > 0; i-- ) 
		if( notes[i-1]["author"] == me->query("id") ) break;
	if( !pointerp(notes) || i > 0 )
	if(!sizeof(notes)) notes = ({ note });
	else
	{
		notes[i-1]["title"] = note["title"];
		notes[i-1]["author"] = note["author"];
		notes[i-1]["msg"] = note["msg"];
		notes[i-1]["time"] = note["time"];
		notes[i-1]["solve"] = "";
	}
	else notes += ({ note });
	tell_object(me, HIM"求救完毕。你的信息已经被加到巫师通知队列里。\n");
	tell_object(me, HIM"巫师正在处理其他玩家，请等待。\n");
	tell_object(me, HIM"你可以先忙你自己的事情，过一段时间后可以用sos read查看是否被解决。\n" NOR);
	save();
	return;
}

void list_bug(object me)
{
	int i;
	string str,s;
	if (sizeof(notes)<1)
	{
		write("没人发出 sos 求救信号。\n");
		return;
	} 
	s = sprintf("玩家已经发出的 sos 列表如下:\n"
"----------------------------------------------------------------------\n");
	for( i = 0; i<sizeof(notes); i++)
	{
		str = sprintf("%d) %-50s %10s %s \n", i+1, notes[i]["title"], notes[i]["solve"]==""?"No solved":"Solved By "+notes[i]["solve"], ctime(notes[i]["time"])[0..9] );
		s = s + str;
	}
	me->start_more(s);		
}

void do_read(object me, int i) 
{
	string s;
	if( i > sizeof(notes) || i < 1)
	{
		write("无此编号!!\n");
		return;
	}
	s = sprintf("%d) %-50s %10s %s\n"
"----------------------------------------------------------------------\n"
		"%s", i, notes[i-1]["title"], notes[i-1]["solve"]==""?"No solved":"Solved By "+notes[i-1]["solve"],
		ctime(notes[i-1]["time"])[0..9], notes[i-1]["msg"] );
		me->start_more(s);
}

int search_id(string id)
{
	int i;
	if( !(i = sizeof(notes)) ) return 0;
	for( ; i > 0; i-- ) 
		if( notes[i-1]["author"] == id ) break;
	return i;
}

int do_solve(object me, int i)
{
	if( i > sizeof(notes) || i < 1)
	{
		write("无此编号!!\n");
		return 0;
	} 
	if ( notes[i-1]["solve"]!="" )
	{
		write(notes[i-1]["solve"]+"已经标志啦!\n");
		return 1;
	}
	notes[i-1]["solve"] = me->query("id");
	save();
	write("该 sos 信息已标志为解决。\n");
	return 1;
}

int main(object me, string arg)
{
	mapping note;
	object where;
	string s, str,arg1; //line 40
	int i,arg2;
/*
	if (file_size(SOS_DIR + SOS_FILENAME) == -1)
	{
		notes = ({ });
		save();
	}
*/
	restore();
	if (!arg)
	{
		if(!wiz_level(me))
		{
			tell_object(me, HIM"你正在" HIY MUD_NAME HIM "里辛苦地挖着泥巴，突然发现一只大个的臭虫向你爬来。\n" NOR);
			tell_object(me, HIM"你赶紧向巫师们发出紧急求救信号：ＳＯＳ！！！\n" NOR);
			where = environment(me);
			if (!where) 
				s=sprintf("%s(%s)求救", (string)me->name(), (string)me->query("id"));
			else
				s=sprintf("%s(%s)在%s(%s)求救", (string)me->name(), (string)me->query("id"), (string)where->query("short"), (string)file_name(where));
			note = allocate_mapping(5);
			note["title"] = s;
			note["author"] = me->query("id"); 
			note["time"] = time();
			note["solve"] = "";
			me->edit( (: done_post, me, note :) );
		}
		else
		{
			list_bug(me);
		}
		return 1;
	} 

	if( sscanf(arg, "%s %s", s, arg1) == 2 )
	{
		if( !wiz_level(me)) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
		if ( s != "solve" ) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
		if ( arg1 =="all" )
		{
			if( !(i = sizeof(notes)) ) return notify_fail("没人发出sos求救信号。\n");
			for( ; i > 0; i-- ) 
				notes[i-1]["solve"] = me->query("id");
			write("所有的 sos 信息已经标志为解决了。\n");
			return 1;
		}
		i = search_id(arg1);
		if( i > 0 )
		{ 
			do_solve( me, i );
			return 1;
		}
	}
	if( sscanf(arg, "%s %d", s, arg2) == 2 )
	{
		if( !wiz_level(me)) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
		if ( s != "solve" ) return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
		do_solve( me, arg2 ); 
		return 1;
	}
	if ( sscanf(arg, "%s", s) == 1 ) 
	switch(arg)
	{
		case "read":
			if( !(i = sizeof(notes)) )
				return notify_fail("还没有人做过 sos 呼叫！\n");
			else
			{
				i = search_id( me->query("id") );
				do_read(me,i);
			}
			break;
		case "list":
			if( !wiz_level(me) )
				return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
			list_bug(me);
			break;
		case "pack":
			if( !wiz_level(me) )
				return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
			if( !(i = sizeof(notes)) )
				return notify_fail("没人发出 sos 求救信号。\n");
			for( ; i > 0; i-- ) 
				if( "" != notes[i-1]["solve"] )
				{
					printf("%s的 sos 求救已被删除！\n", notes[i-1]["author"]);
					if( sizeof(notes) == 1 ) notes = ({});
					else if(i==1) notes = notes[1..sizeof(notes)-1];
					else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
					else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];
				}
			save();
			break;
		case "solve":
			if( !wiz_level(me) )
				return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
				return notify_fail("格式: sos solve <编号或玩家id>\n");
			break;
		default:
			if( !wiz_level(me) )
				return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
			if( sscanf(arg, "%d", i) == 1 ) do_read( me, i );
			else if( sscanf( arg, "%s", str ) == 1 )
			{
				i = search_id(str);
				if( i == 0 )
					return notify_fail("无此玩家发出的 sos 信息！\n");
				do_read( me, i );
			}
	}
	else return notify_fail("格式不对，具体使用方法请参阅 help sos \n");
	return 1;
}

int help(object me)
{
	if (!wiz_level(me) )
	write(@HELP
指令格式 : 
	   sos
	   sos read
    这个指令可以在系统出现bug时来向巫师求助。

    输入该命令后，系统将提示你输入对 bug 的描述。玩家在这里应
该将 bug 出现的情况和系统的提示尽量详细地进行说明，以便巫师修
改该 bug。
    每个玩家只能贴一条 sos，新的 sos 将覆盖以前的输入。
    可以用 sos read 阅读自己贴出的 sos。
HELP
	);
	else 
write(@HELP
指令格式 : 
           sos
           sos <号码或玩家id>
           sos list
           sos pack
           sos solve <号码或玩家id>
    这个指令可以辅助巫师处理玩家提出的 bug 列表。sos 和 sos list 
的功能一样，都是将所有的 bug 信息进行列表。带参数的 sos 命令，根
据参数的不同，将显示对应号码或对应玩家的 bug 的详细信息。sos solve
用来标志某个bug已 经被解决了。sos pack 将删除所有已经标志为解决了
的 bug。
HELP
	);
	return 1;
}
