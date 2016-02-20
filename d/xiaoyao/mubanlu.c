// mubanlu.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "木板路");
	set("long", @LONG
这是一条用木板铺成的小道，虽然不是很长，但是却看得出铺得十
分细心，连一些细微的疏忽也注意到了。道路两旁种着一些奇花异树，
使过路人有心旷神怡的感觉。
LONG );
	set("exits", ([
		"south" : __DIR__"muwu3",
		"north" : __DIR__"xiaodao4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	set("coor/x", 90);
	set("coor/y", -510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}