// /kaifeng/road3.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
御街是条横贯南北的大街道，也是皇帝出巡时的要道。两边的店铺
楼阁不断，实是人间一景。抬眼望去，层层叠叠的房屋已然望不到尽头。
西面那一座大府第便是著名的天波杨府。
LONG);
	set("objects", ([
		__DIR__"npc/fujiazi" : 1,
	]));
	set("outdoors", "kaifeng");
	set("exits", ([
		"east" : __DIR__"yaqi",
		"west" : __DIR__"yangfu",
		"south" : __DIR__"road2",
		"northup" : __DIR__"road4",
	]));

	setup();
	replace_program(ROOM);
}
