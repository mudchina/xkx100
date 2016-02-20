// garden.c

inherit ROOM;
void create()
{
	set("short","花园");
	set("long",@LONG
这是松风观后的一个园子，庭院清幽，异种花卉甚是不少。此处高寒
花卉也异平常，风姿倬约，煞是惹人怜爱。东面通往掌门人卧室，南面是
三清殿。
LONG);
	set("exits",([
		"east"      : __DIR__"woshi",
		"south"     : __DIR__"songfengguan",
	]));
	set("outdoors", "qingcheng");
        set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -820);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
 