// Room: /d/huanggong/guoshiguan.c

inherit ROOM;

void create()
{
	set("short", "国史馆");
	set("long", @LONG
国史馆是翰林儒臣们奉敕纂修国史等书的常设机构. 这里的藏书颇
多. 主要是方志和史书.
LONG
	);
	set("exits", ([
		"northwest"  : __DIR__"wenhua",
	]));
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}