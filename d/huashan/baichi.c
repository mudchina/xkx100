// baichi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "百尺峡");
	set("long", @LONG
走过千尺幢，前面又见另一要命的百尺峡，百尺峡不似千尺幢般险
峻，但亦十分陡峭，岩壁两侧设有铁索以作扶拦。百尺峡又称百丈崖，
是一座壁立千仞的悬崖。崖底到上面的最低的垭口处约百尺，故有是名。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"    : __DIR__"pingxinshi",
		"northdown" : __DIR__"qianchi",
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -890);
	set("coor/y", 230);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
 
