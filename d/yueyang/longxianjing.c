// Room: /d/yueyang/longxianjing.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "龙涎井");
	set("long", @LONG
龙涎井在龙舌山下，这里的井水清澈纯净，四时不涸，是龙舌头上
面一点点滴下的涎水，故称“龙涎井”。井内赭黄色岩石形象龙舌，泉
水从岩石上注入井内，一点一滴，好似涎水。过去井水终年不涸，清澈
见底，冬暖夏凉。故老相传，用龙涎井的水泡君山茶，喝了百病皆除，
长生不老。古人信以为真，远道乘舟来取龙涎者络绎不绝。《君山茶歌
》云：“试挹龙涎烹雀舌，烹来长似君山色”，足见珍贵。
    距井口三尺远处，立一对雕龙柱坊，高近丈，门宽四尺，门楣上镌
刻“龙涎井”三个苍劲有力的正楷大字。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"south"   : __DIR__"longkou",
		"northup" : __DIR__"feilaizhong",
	]));
	set("coor/x", -1720);
	set("coor/y", 2300);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
