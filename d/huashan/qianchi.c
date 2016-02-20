// qianchi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "千尺幢");
	set("long", @LONG
前面有一斜如天垂石梯的山阶，这就是赫赫有名的千尺幢，千尺幢
是依一陡峭岩脊的裂缝开凿而成，斜度约七十度，高约二十米，仅容一
人上落。抬头仅见一线天光，两旁岩壁陡峭，尽头是个仅能容身的方形
石洞，俗称“天井”，天井旁的危崖上刻有“太华咽喉”的题刻。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"huixinshi",
		"southup" : __DIR__"baichi",
	]));
	set("objects", ([
		__DIR__"npc/youke": 2,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -890);
	set("coor/y", 240);
	set("coor/z", 40);
	setup();
}
 
int valid_leave(object me, string dir)
{
	if (dir == "southup" && userp(me))
	{
		me->receive_damage("jing", 30);
		me->receive_damage("qi", 30);
	}
	return 1;
}
