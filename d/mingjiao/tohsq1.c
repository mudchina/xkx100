//TOHSQ1.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
这里是一条很普通的山路，路边的树林密集，芳草流香，草丛中星
星点点地点缀着一些白色野花，一股清泉叮叮咚咚地向山下流淌，远处
传来阵阵水声，为这山谷陡增了几分气势。
LONG );
	set("exits", ([
		"southeast" : __DIR__"torjq3",
		"northwest" : __DIR__"tohsq2",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52010);
	set("coor/y", 870);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}