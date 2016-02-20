// home.c
// Last Modified by winder on Mar. 10 2000
// standard home for players.
int list_invite();
string *r_invited=({});

#include <ansi.h>

inherit F_SAVE;
inherit ITEM;

string out="/d/taohuacun/taohua7";

int save_room();
int do_bed();
string check_str(string str);
object find_bed(object me);
void get_long_text(string str, string text);
void get_bed_long_text(string str, string text);

int is_home() {return 1;}

void create()
{
	 set_name("新房",({"room"}));
	 set("short", "标准新房");
	 set("long", @LONG

一切都设置好了，只等一些室内装修。
LONG
	 );
	 set("home_host",({"def_host"}));
	 set("exits", ([
		"out": out,
	 ]));
	 set_max_encumbrance(100000000);
	 set_weight(10000000);
	 set("no_get",1);
	 set("no_beg",1);
	 set("no_steal",1);
	 set("no_fight", 1);
	 seteuid(getuid());
	 setup();
}

void init()
{
	 object me=this_player(), env=this_object();
	 object *present;
	 string id,*home_host,*invited;
	 int i,inv,j,k;

	 if(env==environment(me))
	 {
		 set_name(this_object()->query("short"), ({this_object()->query("file_name")}));
		 id=(me->parse_command_id_list())[0];
		 home_host=env->query("home_host");

		 if (member_array(id,home_host)==-1 && !me->query("is_baby"))
		 {
//			 invited=me->query_temp("invited");
			 inv=0;
/*			 if(invited)
			 {
				 for(i=0;i<=sizeof(invited)-1;i++)
				 {
					 if(member_array(invited[i],home_host)>-1)
					 {
						 inv=1;
						 break;
					 }
				 }
			 }
*/		 if (sizeof(r_invited) && member_array(me->query("id"),r_invited)> -1)
			  inv = 1;
		  if (wizardp(me) && me->query("env/invisibility"))
			  inv = 1;
			 if(inv==1)
			 {
				 present=all_inventory(env);
				 j=sizeof(present);
				 k=0;
				 if(j)
				 {
					 for(i=0; i<j; i++)
					 {
						 if(member_array(present[i]->query("id"),home_host)>-1)
						 {
							 k=1;
							 break;
						 }
					 }
				 }
				 if(!k)
				 {
					 write("主人不在家，您还是呆会儿再来吧。\n");
					 me->move(out,1);
					 tell_room(out,me->query("name")+"失望地走了出来。\n",({me}));
					 return;
				 }
			 }
			 else
			 {
				 tell_object(me, "啊哈！ 闯进来了！\n");
				 tell_object(me, "某某飞起一脚，正好踢中你的屁股 。\n");
				 tell_object(me, "某某飞起一脚，正好踢中你的屁股 。\n");
				 me->move(out,1);
				 tell_room(out,me->query("name")+"似乎被人一脚踢了出来，神色有点狼狈。\n", ({me}));
				 return;
			 }
			 tell_room(env,me->query("name")+"拉开门，走了进来。\n",({me}));
		 }
		 add_action("do_bed", "gosleep");
		 add_action("do_bed", "gobed" );
		 add_action("do_bed", "bed");
		 add_action("go_out", "out");
		 find_bed(me);
		 if (member_array(me->query("id"),home_host)>-1)
		 {
			 add_action("set_long", "homedesc");
			 add_action("set_short", "homename");
			 add_action("set_bed_long", "beddesc");
			 add_action("set_bed_short", "bedname");
			 add_action("do_findbaby","findbaby");
			 add_action("do_invite","invite");
			 add_action("do_invite","yaoqing");
		 }
	 }
	 return;
}
int do_invite(string arg)
{
	object me=this_player();
  object home=this_object();
  object who;
 
	if (!arg)  
		return list_invite();
 
	if (sscanf(arg,"-d %s",arg)==1)
	{
		if (!sizeof(r_invited) || member_array(arg,r_invited)== -1)
			return notify_fail(arg+"并没有在邀请名单上。\n");
		write("从邀请名单上删除"+arg+"...");
		r_invited -= ({arg});
		write("成功。\n");
		return list_invite();
	}
	if (  sizeof(r_invited)>0 && member_array(arg,r_invited) > -1  )
		return notify_fail(arg+"已经在邀请名单上了。\n");
    write("添加"+arg+"到邀请名单。\n");
	if (who=find_player(arg))
    tell_object(who,me->query("name")+"("+me->query("id")+")告诉你：到我的"+home->query("short")+"看看吧。\n");
//记录在本房间
	if (!sizeof(r_invited))
		r_invited = ({arg});
	else if ( member_array(arg,r_invited) == -1 )
		r_invited += ({arg});
	return list_invite();
}

int list_invite()
{
	object room=this_object();
	int size;
	int i;
	if (!sizeof(r_invited))
	 return notify_fail("没有任何人在家里的邀请名单上。\n");
  size=sizeof(r_invited);
  write("家里目前邀请的人员为：("+implode(r_invited[0..size-1],"、")+")\n");
  return 1;
}
	
int do_findbaby()
{
	object me=this_player(),*list,*parents,baby,where;
	int number,size,i,j,found;
	string myid,*babyid;

	number=me->query("child");
	if(number==0) return notify_fail("您还没有生下孩子呢。:)\n");

	myid=me->query("id");

	list=children("/d/taohuacun/npc/baby");
	size=sizeof(list);

	for(i=1;i<=number;i++)
	{
		found=0;
		if(size>0)
		{
			for(j=0;j<size;j++)
			{
				if(list[j]->query("saveid")==me->query("child_"+i+"/saveid"))
				{
					where=environment(list[j]);
					if(where)
					{
						found=1;
						write(list[j]->query("name")+"现在在");
						if(where->query("short"))
						{
							write(where->query("short"));
						}
						else
						{
							write(where->short());
						}
						write("。\n");
						break;
// If one have more than one boys or girls, break here after first match.
					}
				}
			}
		}
		if(found==0)
		{
			if(me->query("child_"+i+"/id"))
			{
  			babyid=me->query("child_"+i+"/id");
				baby=new("/d/taohuacun/npc/baby");
				baby->set("saveid",me->query("child_"+i+"/saveid"));
				seteuid(baby->query("saveid"));
				export_uid(baby);
				if (!baby->restore())
				{
					baby->set("long",me->query("child_"+i+"/long"));
					baby->set("gender",me->query("child_"+i+"/gender"));
					baby->set("parents",me->query("child_"+i+"/parents"));
					baby->set("saveid",me->query("child_"+i+"/saveid"));
					baby->set("potential",100);
				}
				if (baby->query("die")>=3)
					destruct(baby);
				else 
				{
					baby->set_name(me->query("child_"+i+"/name"),babyid);
					baby->update_me();
					baby->move(environment(me));
					message_vision("你忽然看到床底下"+ ({"探出一颗小脑瓜","伸出一双小脚丫","伸出一支小手"})[random(3)]+"．．．\n",me);
				}
			}
			else
			{
				write("Error: don't have data for baby "+i+". Please report to wiz. :)\n");
			}
		}
	}
	return 1;
}

object find_bed(object me)
{
	object env,*inv,table,card,jing,bed,home=this_object();
	string str;
	int i;
	env=environment(me);
	inv=all_inventory(env);
	if(i=sizeof(inv))
	{
		for(i=0; i<sizeof(inv); i++)
		{
			if (inv[i]->query("id")=="bed")
			{
				bed=inv[i];
				break;
			}
		}
	}

	if(!bed)
	{
		table=new(__DIR__"table");
		table->move(home);
		card=new(__DIR__"card");
		card->move(table);
		jing=new(__DIR__"jing");
		jing->move(table);
		bed=new(__DIR__"bed");
		bed->set("out",this_object());
		if(strlen(str=home->query("bed_short"))>1)
		{
			bed->set("short",str);
			bed->set_name(str,({bed->query("id")}));
		}
		if(strlen(str=home->query("bed_long"))>1)
		{
			bed->set("long",str);
		}
		bed->move(home);
	}
	return bed;
}

int do_bed()
{
	object me=this_player(),bed;
		 if (member_array(me->query("id"),this_object()->query("home_host")) == -1)
		  return notify_fail("别人家里的床看看就好了，爬上去主人会生气的。\n");
	bed=find_bed(me);
	message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
	if(!me->move(bed))
	{
		write(HIY "床上已经挤不下了！\n" NOR);
	}
	else
	{
		message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
	}
	return 1;
}

string query_save_file()
{
	return DATA_DIR"playerhomes/"+this_object()->query("file_name");
}

int save_room()
{
	string file;

	file=this_object()->query_save_file();
	write("存档 ．．．．．\n");
	if( save() )
	{
		write("Ok.\n");
		return 1;
	}
	else
	{
		write("你没有写入这个档案的权利。\n");
		return 0;
	}
}

int go_out()
{
	object me=this_player();
	tell_room(this_object(),me->query("name")+"推开门，走了出去。\n",({me}));
	me->move(out);
	message_vision("$N推开门，走了出来。\n",me);
	return 1;
}

int set_short(string str)
{
	if(!str) return 0;

	str=check_str(str);
	set("short",str);
	set_name(this_object()->query("short"), ({this_object()->query("file_name")}));
	save_room();
	return 1;
}

int set_bed_short(string str)
{   object bed;
	if(!str) return 0;

	str=check_str(str);
	if(objectp(bed=present("bed",this_object())) && bed->query("id") == "bed")
	{
		set("bed_short",str);
		bed->set("short",str);
		bed->set_name(str,({bed->query("id")}));
		save_room();
		return 1;
	}
	return 0;
}

int set_long()
{
	string str;
	this_player()->edit( (:get_long_text, str :) );
	return 1;
}

int set_bed_long()
{
	string str;
	this_player()->edit( (:get_bed_long_text, str :) );
	return 1;
}

void get_long_text(string str, string text)
{
	str=check_str(text);
	set("long",str);
	save_room();
	return;
}

void get_bed_long_text(string str, string text)
{
	object bed;

	str=check_str(text);
	set("bed_long",str);
	if(objectp(bed=present("bed",this_object())))
	{
		bed->set("long",str);
	}
	save_room();
	return;
}

string check_str(string str)
{
	str=replace_string(str,"\"","");
	str=replace_string(str,";","");
	str=replace_string(str,"\\","");
	str=replace_string(str,"/","");
	str=replace_string(str,"'","");
	str=replace_string(str,"`","");
	str=replace_string(str,",","");
	str=replace_string(str,"!","");
	str=replace_string(str,"~","");
	str=replace_string(str,"{","");
	str=replace_string(str,"}","");
	str=replace_string(str,"$","");
	str=replace_string(str,"&","");
	return str;
}

int clean_up()
{	//clean_up homes
	object *inv,*inv1;
	int i,j;

	if( !clonep() && this_object()->query("no_clean_up") ) return 1;

	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
	{
		if(userp(inv[i]) || inv[i]->query("is_baby")) return 1;
		if(inv[i]->query("if_bed"))
		{  //a bed object
			inv1=all_inventory(inv[i]);
			if(sizeof(inv1)>0)
				for(j=sizeof(inv1)-1; j>=0; j--)
				{
					if (userp(inv1[j]) || inv[i]->query("is_baby")) return 1;
				}
		}
	}

	destruct(this_object());
	return 0;
}
