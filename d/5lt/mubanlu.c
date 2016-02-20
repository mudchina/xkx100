// Room: /d/5lt/mubanlu.c

inherit ROOM;

void create()
{
	set("short", "木板路");
	set("long", @LONG
这是电视台新近铺好的木板路，踩上去咯吱咯吱作响。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"enter" : __DIR__"dating",
		"south" : __DIR__"xiaodao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -185);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
