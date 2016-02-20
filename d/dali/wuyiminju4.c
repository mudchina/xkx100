//Room: /d/dali/wuyiminju4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","乌夷民居");
	set("long",@LONG
这是一座用木柴及兽皮搭成的乌夷民居。此地的村民主要从事耕
作，由于实行换季轮耕，不得不经常迁徙，因而房舍都颇简陋，说是
房舍，倒不如说更象帐篷，拆、建都甚方便。
LONG);
	set("objects", ([
	   __DIR__"npc/kid": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yixibu",
	]));
	set("coor/x", -89990);
	set("coor/y", -70040);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/wymj4",1);
	}
}