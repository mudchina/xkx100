// Room: /d/5lt/exit.c

inherit ROOM;

void create()
{
	set("short", "村口");
	set("long", @LONG
这里是扬州郊外，虽然远离县城，却没有什麽山贼草寇在附近出没。
西面是一个小村庄，村民们过着日出而作，日落而息的宁静生活，俨然
世外桃源怡然自得的样子。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"qsroad",
		"east" : "/d/taohuacun/taohua1",
	]));
        set("objects", ([
        ]) );
//	set("no_clean_up", 0);
        set("outdoors", "5lt" );
	set("coor/x", -110);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}