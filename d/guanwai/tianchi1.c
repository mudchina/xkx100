// /guanwai/tianchi1.c

inherit ROOM;

void create()
{
	set("short", "长白天池");
	set("long", @LONG
“天池在长白山巅中心点，群峰环抱，离地高约二十里，故名天池
。”天池碧波盈盈，清澈湛蓝。湖周围峭壁百丈，峰影云影倒映其中，
湖光山色、岚影云天十分诱人。湖岸周遭芳草茵茵，百花吐艳。古人诗
云：“周迥八十里，峭壁立池边。水满疑天池，云低别有天。江山宜漫
画，鹿逐结前缘。予卜携书隐，遨游慰晚年。”
LONG );
	set("exits", ([
		"south"    : __DIR__"tianchi2",
		"northup"  : __DIR__"longmen",
		"westup"   : __DIR__"baiyun",
		"eastup"   : __DIR__"huagai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}