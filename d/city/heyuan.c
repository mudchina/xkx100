// Room: /city/heyuan.c

inherit ROOM;

void create()
{
	set("short", "何园");
	set("long", @LONG
何员外修的何园是扬州城中数一数二的好园林，就是传到江南也颇
有些名声，园内假山水池错落有致，一草一木，别具匠心，往往细微之
处却又有曲径通幽之感。满目芳华，扑鼻芬香，令人陶醉。
LONG );
	set("outdoors", "yangzhouw");
	set("exits", ([
		"north" : __DIR__"caohenanjie",
		"south" : __DIR__"heyuanhouyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -51);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}