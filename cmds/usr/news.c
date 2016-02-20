// news cmds
// by Doing
 
inherit F_CLEAN_UP;
#include <ansi.h>

#define LOCATION "/u/qingyun/workroom"
#define Nboard "/clone/board/news_b"
string bshort();
int do_look();
int do_read(string arg);
object board;
	
int main(object me, string arg)
{
	seteuid(getuid(me));
	board=find_object(Nboard);
	if (!board) 
	{
		board=new("/clone/board/news_b");
    if ( !find_object(LOCATION) )
      call_other(LOCATION,"???");
    call_other(Nboard,"???");
    if (	board=find_object(Nboard))
      board->restore();
    else
      return notify_fail("更新榜有错，请同时巫师解决。\n");
  }  
        if (! arg || arg == "" )
        {
                tell_object(me,bshort());
                return 1;
        }
        if (arg == "all")
        {//news all == l board
                return do_look();
        }

        if (sscanf(arg, "discard %s", arg))
        {
                return board->delete_post(arg);
        }

        if (sscanf(arg, "post %s", arg))
        {
       		 	if (! wizardp(me) || ! interactive(me))
       			 {
                tell_object(me, "只有巫师才能发布新闻。\n");
                return 1;
       	 		}               
        			if (replace_string(arg, " ", "") == "")
         		       arg = "无标题";
         		  board->do_post(arg);
         		  return 1;
/*                if (board->do_post(arg))
                 {
         shout(HIC "【侠客行一百】" NOR + WHT + me->name() + WHT "[" +
             me->query("id") + WHT "]发布了一条新闻，请用(news)命令查看。\n" NOR);

        tell_object(me, HIC "【侠客行一百】" NOR + WHT + me->name() + WHT "[" +
             me->query("id") + WHT "]发布了一条新闻。\n" NOR);

        tell_object(me, "新闻发布完成。\n");
                	return 1;
                 	}
                 return 0;*/
        }

       // return board->do_read(arg);
          return do_read(arg);
}
//string bshort(object board)
string bshort()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = board->query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return " [ 目前没有任何更新消息 ]\n";

	if( this_player() )
	{
		last_read_time = (int)this_player()->query("board_last_read/" + (string)board->query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		
		return 
		sprintf(HIW"侠客行一百总共发布过"HIY"%s"HIW"条更新消息，其中"HIR"%s"HIW"篇未读。\n"NOR,chinese_number(sizeof(notes)),chinese_number(unread));
	else
		return sprintf(HIW"侠客行一百总共发布过"HIY"%s"HIW"条更新消息，目前没有任何未读过的消息。\n"NOR, chinese_number(sizeof(notes)));
}

//news all  ==  look board  
//int do_look(object board)
int do_look()
{
	mapping *notes;
	int i, t, max,size,num,last_time_read;
	string msg, myid;
	object ob = board;
	object me = this_player();
	notes = ob->query("notes");
	size = ((int)sizeof(notes)-1)/20;
	if( !pointerp(notes) || !sizeof(notes) ) 
	{
		msg="[ 目前没有任何更新消息 ]\n";
		message("vision", msg, me);
		return 1;
	}
	
	msg="侠客行一百最近的更新消息如下：\n"
	HIW"编号"NOR"──"HIY"标题"NOR"────────────────────"HIR"作者"NOR"─"HIG"回复数"NOR"───"HIM"时间"NOR"─────"NOR;
	last_time_read = me->query("board_last_read/news_b");
	message("vision", msg, me);
//	for(t=0; t<=size; t++)
    for(t=size;t>=0;t--)
    	{
//    		num = t*20;                0-20  0-62 共63个消息  size=3
        num = (sizeof(notes)-1)-(size-t)*20;      // (24-1)-(1-2)   num=62 42 22 2
//    		max = num + 20;
        max = num-20;          //          max=42 22 2 -18
//    		if( max > sizeof(notes)) max = (int)sizeof(notes);
        if( max <0 ) max = -1;  //         max=42 22 2 -1
    		i=num;                 //         i= 62 42 22 2
      	msg = sprintf("\n%s[%2d]"HIR" %s "HIY"%-29s"HIR" %20s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:HIW), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"]+"("+notes[i]["owner"]+")", sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
      //                 HIR[21]       M     title       qingyun  +0
//                                         msg= post 62 42 22 2
//    		for(i=num+1; i<max; i++)   // note[1]-note[19]  0-19
        for (i=num-1; i>max;i--)     //i=61,43  41,23 21,3  1,0 
    		{
//        msg += sprintf("\n%s["HIW"%2d"NOR"]"HIR" %s "HIY"%-29s"HIR" %12s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:""), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
        msg += sprintf("\n%s[%2d]"HIR" %s "HIY"%-29s"HIR" %20s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:HIW), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"]+"("+notes[i]["owner"]+")", sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
    		}
    		message("vision", msg, me);
        }
        
/*      i = sizeof(notes);
      msg = "";
      while(i--)
          msg += sprintf("\n%s["HIW"%2d"NOR"]"HIR" %s "HIY"%-29s"HIR" %12s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:""), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
    	message("vision", msg, me);
*/        msg = "\n───────────────────────────────────────────\n";
        msg += sprintf("共有 %d 条消息。\n", sizeof(notes));
    	message("vision", msg, me);
    	return 1;
}
void check_me(object me)
{
	mapping *notes;
	int i, unread, last_read_time;
	object board;
	seteuid(getuid(me));
//	board=find_object("/clone/board/news_b");
//	if (!board) board=new("/clone/board/news_b");
	board=find_object(Nboard);
	if (!objectp(board)) 
	{
    if (!find_object(LOCATION))
      call_other(LOCATION,"???");
    call_other(Nboard,"???");
    if (	board=find_object(Nboard))
      board->restore();
    else
      return;
 }  
	notes = board->query("notes");
	if( !pointerp(notes) || !sizeof(notes) )	return;
	if( me )
	{
		last_read_time = (int)me->query("board_last_read/" + (string)board->query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		{
      if (!me->query_temp("news"))
			tell_object(me,HIY"在你离线期间侠客行一百有过更新消息，请仔细阅读以下内容。\n\n"NOR);
      me->set_temp("news",1);
      seteuid(ROOT_UID);
      me->force_me("news new");
    }
  if (unread > 1 ) 
  {
  	remove_call_out("check_me");
//  	call_out("check_me",60,me);  
  }
}

int do_read(string arg)
{
	int num, rep, last_read_time,i,last;
	mapping *notes;
	string myid,msg,file;
	object me=this_player();

	last_read_time = me->query("board_last_read/" + board->query("board_id"));
	myid = board->query("board_id");
	notes = board->query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("版上目前没有任何贴子。\n");

	if( !arg ) return notify_fail("指令格式：read <贴子编号>[.<回复编号>]|new|next|old\n");

// 显示以前备份的旧贴子
	if (arg=="old")
	{
		file=DATA_DIR+"board/"+board->query("board_id")+".old";
		if (file_size(file)<=0) return notify_fail("对不起，目前本版没有保存的旧贴。\n");
		else
		{
			msg=read_file(file);
			me->start_more(msg);
			return 1;
		}
	}
// 显示未读的贴子
	if( arg=="new" || arg=="next" )
	{
		if( !intp(last_read_time) || undefinedp(last_read_time) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"]>last_read_time) break;
	} else if( sscanf(arg, "%d.%d", num, rep)==2 )
		{
			if( num < 1 || num > sizeof(notes) )
				return notify_fail("没有这个贴子。\n");
			else num--;
			if( rep < 1 || rep > sizeof(notes[num]["re"]) )
				return notify_fail("没有这个回复。\n");
			else rep --;
//			me->start_more( sprintf(
			tell_object(me, sprintf(
		"[ "HIW"编号："NOR"%2d | "HIW"回复编号："NOR"%2d] [ "HIW"原题："NOR"%-27s ] \n"
		"[ "HIW"回复标题："NOR"%-50s ]\n────────────────────────────────\n"
		"%s\n────────────────────────────────\n[ "HIW"时间："NOR"%s ] [ "
		HIW"作者："NOR" %19s]\n",
			num + 1, rep + 1,
			notes[num]["title"],
			notes[num]["re"][rep]["title"],
			notes[num]["re"][rep]["msg"],
			ctime(notes[num]["re"][rep]["time"]),
			notes[num]["re"][rep]["author"]+"("+
			notes[num]["re"][rep]["owner"]+")"));

		if( notes[num]["time"] > last_read_time )
			me->set("board_last_read/" + board->query("board_id"),
				notes[num]["time"]);

		return 1;
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几个贴子的回复？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这个贴子。\n");
	num--;
	msg=sprintf(
	"[ "HIW"编号："NOR"%2d ] [ "HIW"作者："NOR"%20s ] [ "HIW"时间："NOR"%-9s ]\n[ "
	HIW"标题："NOR"%-54s ]\n────────────────────────────────\n%s\n"
	"──────────────────────────["HIW" 本 篇 完 "NOR"]\n",
		num + 1,
		notes[num]["author"]+"("+notes[num]["owner"]+")",
		ctime(notes[num]["time"])[0..9],
		notes[num]["title"],
		notes[num]["msg"],);
// 显示回复的数目
	if (sizeof(notes[num]["re"])&&me->query("env/show_reply")!="all") msg+=sprintf(HIW"回复："NOR"%d 份。\n",sizeof(notes[num]["re"]));
// 显示最后的一个回复
	if (me->query("env/show_reply")=="last")
	{
		last=sizeof(notes[num]["re"])-1;
		msg+=sprintf(
			"\n[ "HIW"回复编号："NOR"%2d] [ "HIW"回复标题："NOR"%-34s ] \n"
			"────────────────────────────────\n"
			"%s\n────────────────────────────────\n[ "HIW"时间："NOR"%s ] [ "
			HIW"作者："NOR" %19s]\n",
			last+1,
			notes[num]["re"][last]["title"],
			notes[num]["re"][last]["msg"],
			ctime(notes[num]["re"][last]["time"]),
			notes[num]["re"][last]["author"]+"("+
			notes[num]["re"][last]["owner"]+")");
	}
// 显示所有的回复
	if (me->query("env/show_reply")=="all")
	{
		for (i=0;i<sizeof(notes[num]["re"]);i++)
		{
			msg+=sprintf(
		"\n[ "HIW"回复编号："NOR"%2d] [ "HIW"回复标题："NOR"%-34s ] \n"
		"────────────────────────────────\n"
		"%s\n────────────────────────────────\n[ "HIW"时间："NOR"%s ] [ "
		HIW"作者："NOR" %19s]\n",
			i+1,
			notes[num]["re"][i]["title"],
			notes[num]["re"][i]["msg"],
			ctime(notes[num]["re"][i]["time"]),
			notes[num]["re"][i]["author"]+"("+
			notes[num]["re"][i]["owner"]+")");
		}
	}
//	me->start_more(msg);
			tell_object(me, msg);
	if( notes[num]["time"] > last_read_time )
		me->set("board_last_read/" + board->query("board_id"),
			notes[num]["time"]);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : news [next] | [<新闻编号>] | new | all

这条指令让你你可以阅读游戏中的新闻。所有的更新和消息都是通过
新闻发布的。

使用 new 参数可以让你阅读还没有读过的新闻。
使用 all 参数可以让你查看系统目前所有的新闻。

巫师可以通过news post <标题>来发布新闻。
            news discard来删除自己发布的新闻。
HELP );
    return 1;
}
