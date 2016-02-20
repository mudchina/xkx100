//Room: /d/dali/hudiequan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","蝴蝶泉");
	set("long",@LONG
蝴蝶泉就显得更加清凉湿润，大量的蝴蝶，从四面八方，汇集在树荫下，
花丛中，翩翩起舞，成千上万只彩蝶，欢聚一处，使这里变得花团锦簇。特
别是在蝴蝶泉上，顺着那倒垂的扬柳，无数蝴蝶，一只咬着一只的尾部，形
成千百个蝶串，人来不惊，投石不散，构成令人惊叹的奇观。
LONG);
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yuxuguanqian",
	    "east"   : __DIR__"xiaodao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -39000);
	set("coor/y", -69000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}