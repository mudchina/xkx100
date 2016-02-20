//Room: wdbl2.c 武当柏林
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","柏林");
	set("long",@LONG
你穿行在一片茂密的柏林中，阴森郁翠，怪石嶙峋，草深没人。有
几个伐木道士正在奋力砍(chop)树，不时地惊起兔子从你的身边飞跑而
过。
LONG);
	set("objects", ([
		__DIR__"obj/cypress" : 1,
		CLASS_D("wudang")+"/famu" : 1,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"west"     : __DIR__"wdbl",
	]));
	set("coor/x", -2050);
	set("coor/y", -820);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
