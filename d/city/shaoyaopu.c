// Room: /city/huapeng.c

inherit ROOM;

void create()
{
	set("short", "芍药圃");
	set("long", @LONG
扬州芍药，擅名天下，禅寺前的这块芍药圃尤其宏伟，只见花圃中
名种千百，花大如碗，煞是瑰丽。当日影渐渐西斜。日光照在花棚外数
千株芍药之上，璀灿华美，真如织锦一般。其中一株芍药开了四朵大花，
花瓣深红，腰有金线，便是著名的金带围了。
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"chanzhimenqian",
		"west"  : __DIR__"huadian",
	]));
	set("coor/x", -30);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}