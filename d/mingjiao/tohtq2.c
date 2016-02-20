//TOHTQ2.C

inherit ROOM;

void create()
{
	set("short", "山谷路");
	set("long", @LONG
这里是一条很普通的山路，路边的树林密集，芳草流香，草丛中星
星点点地点缀着一些白色野花，渐行渐低，两边草木茂盛，处高崖下，
天色渐阴。
LONG );
	set("exits", ([
		"southwest" :__DIR__"tohtq1",
		"northdown" :__DIR__"tohtq3",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 880);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}