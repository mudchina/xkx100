//ROOM: /d/yanziwu/biheqiao.c

inherit ROOM;

void create()
{
	set("short", "碧荷桥");
	set("long",@LONG
密密匝匝的荷叶上面，一条曲曲折折的小桥通向水中的一片小洲，
洲上花红柳绿，似乎别有洞天。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"tingxiang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}