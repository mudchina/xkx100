// /d/xingxiu/beijiang.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "伊犁城");
	set("long", @LONG
伊犁位于北面天山雪水汇集而成的伊犁河以北。城内聚居着维吾尔
族人，人来人往，十分热闹。只是他们说的话你听不懂。城西有家小店
铺，西北边人声鼎沸，好像在举行什么比赛。北边是一家客栈。客栈内
附一家马厩。东面有家院落，院门口有棵大树。
LONG );
	set("exits", ([ 
	    "west"      : __DIR__"store",
	    "east"      : __DIR__"house",
	    "south"     : __DIR__"yiligate",
	    "northwest" : __DIR__"saimachang",
	    "north"     : __DIR__"kezhan",
	]));
	set("objects", ([
		__DIR__"npc/woman": 2 ]) );
//	set("no_clean_up", 0);
	set("outdoors", "xiyu");

	set("coor/x", -39000);
	set("coor/y", 13000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

