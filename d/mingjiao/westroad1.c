//westroad1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条直通西方的山路，向西远望，群山巍峨，云雾飘渺，再往
前不远，就要进入深山之中了。东面就是去中原的路。
LONG);
	set("exits",([
		"west" : __DIR__"westroad2",
		"east" : "/d/xingxiu/silk4",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
