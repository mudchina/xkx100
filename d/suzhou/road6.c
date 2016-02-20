// Room: /d/suzhou/road6.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "湖畔大道");
        set("long", @LONG
你走在一条青石大道上，往北遥看，灵岩山展现在你的面前。从这
里向南遥看太湖景色，烟波浩森，气象万千。放棹太湖之上，耸嶂叠翠，
千顷一壁，倒影楚楚；鼋头眺望，群山来去，岛屿浮水；苍茫水面，鱼
帆千张；湖中有湖，水天相接。若赶上傍晚彩霞满天时，湖面金波顷流，
令人心旷神怡。
LONG);
	set("outdoors", "suzhou");
	set("exits",([
		"north" : __DIR__"road7",
		"south" : __DIR__"road5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

