#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","剑冢");
	set("long",@LONG
平台上大石「剑冢」两个大字之旁，尚有两行字体较小的石刻：
        「剑魔独孤求败既无敌于天下，乃埋剑于斯。
          呜呼！群雄束手，长剑空利，不亦悲夫！」
大石之下，许多石块堆着一个大坟，背向山谷，俯仰空阔，占尽了
形势。想剑魔文武全才，抱负非常，但恨生得晚了，无缘得见这位
前辈英雄，你不禁仰天长叹，豪情万千。
LONG
	);
	set("no_clean_up",1);
	set("move_stone",1);
	set("outdoors", "jianzhong");
	set("coor/x", -401);
	set("coor/y", -421);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_move","move");
	add_action("do_move","ban");
	add_action("do_climb","climb");
}
int do_move(string arg)
{
	object me,room,ob,ob1,ob2,ob3;
	me=this_player();
	room=this_object();
	if((arg!="stone")&&(arg!="石块"))
	{	
		return notify_fail("你要搬什么？\n");
	}	else	
	{
		if(!room->query("move_stone"))
			return notify_fail("石块已被人搬开了！\n");
		message_vision("$N搬开了冢上的石块，露出了并列的三柄长剑，在第一、二把长剑\n之间，另有一块长石条片。三把剑和石片并列于一块大青石之上。\n",me);
		room->set("move_stone",0);
		ob=new(WEAPON_DIR"treasure/qingguang-jian");
		if ( ob->violate_unique() ) destruct( ob );
		else ob->move(room);
		ob1=new("/clone/book/shipian");
		if ( ob1->violate_unique() ) destruct( ob1 );
		else ob1->move(room);
		ob2=new(WEAPON_DIR"treasure/xuantie-jian");
		if ( ob2->violate_unique() ) destruct( ob2 );
		else ob2->move(room);
		ob3=new(__DIR__"obj/mujian");
		ob3->move(room);
	}	
	return 1;
}
int do_climb(string arg)
{
	object me;
	me=this_player();
	if(arg!="down")	return notify_fail("你要往哪儿爬？\n");
	message_vision("$N顺着来路爬了下去。\n",me);
	me->move(__DIR__"qiaobi");
	message_vision("$N从「剑冢」上爬了下来。\n",me);
	return 1;
}
