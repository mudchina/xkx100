//Room: /d/dali/sanglin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","桑林");
	set("long",@LONG
一大片桑树林生长在低山的缓坡山腰上。养蚕、纺丝是摆夷族的
重要副业，摆夷妇女大都擅织丝，编织自己穿着的短裙，也用来和邻
近部落交换些其它物品。一群摆夷姑娘正在林间忙着采摘桑叶。
LONG);
	set("objects", ([
	   __DIR__"npc/caisangnu": 1,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "northdown"  : __DIR__"yangzong",
	]));
	set("coor/x", -30960);
	set("coor/y", -70620);
	set("coor/z", 30);
	setup();
}
void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/sl",1);
	}
}