// /yubifeng/dating.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @long
大厅看来极大，四角各生着一盆大炭火。厅上居中挂着一副木板对
联，写着廿二个大字：“不来辽东大言天下无敌手，邂逅冀北方信世间
有英雄”。上款是“希孟仁兄正之”，下款是“妄人苗人凤深惭昔年狂
言醉后涂鸦”。
long );
	set("exits", ([
		"south" : __DIR__"changlang",
		"west"  : __DIR__"zoulang1",
		"east"  : __DIR__"zoulang2",
	]));
	set("objects", ([
		__DIR__"npc/duximeng" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6120);
	set("coor/y", 5180);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
