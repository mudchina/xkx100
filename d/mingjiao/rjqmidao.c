//RJQMIDAO.C

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
这里是一条秘道的尽头，石墙之上嵌入两盏油灯，火苗倏忽，向前
望去，黑暗中不知所往。
LONG );
	set("exits", ([
		"north" : __DIR__"rjqjiguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 840);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

