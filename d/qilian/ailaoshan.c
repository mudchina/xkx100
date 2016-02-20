// Room: /d/qilian/ailaoshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "哀牢山");
	set("long", @LONG
此山毫无生气，寸草不生，一但踏入山中, 顿感一股莫可名状的怪
捩之息，传说中的神仙刑天想刺杀天帝，没有成功，天帝砍了他的头。
刑天以脐为嘴，双乳为目，继续和天帝作战，失败後被困於此山。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"southeast" : __DIR__"tieshishan",
		"southwest" : __DIR__"zibaipo",
	]));
	set("no_clean_up", 0);
	set("coor/x", -13500);
	set("coor/y", 3500);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}