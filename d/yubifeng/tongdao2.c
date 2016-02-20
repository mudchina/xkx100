// /yubifeng/tongdao2.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "通道");
	set("long", @LONG
洞穴愈来愈窄，须得弓身而行方能通过，洞中到处是千年不化的尖
冰，有些处所的冰条如刀剑般锋锐突出。有时头顶撞上了坚冰尖角，隐
隐生疼。
LONG );
	set("exits", ([
		"north" : __DIR__"shimen",
		"west"  : __DIR__"tongdao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
