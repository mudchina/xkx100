// Room: /d/luoyang/futusi.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "负图寺");
	set("long",  @LONG
河图洛书为华夏文明之源头。《易》曰：“河出图，洛出书，圣人
则之。”相传，距今七、八千年之伏羲时代，一龙马从黄河跃出，其身
刻有“一六居下，二七居上，三八居左，四九居右”之数字，此为河图。
伏羲依照河图而演绎为八卦。据说这里就是当年“龙马负图”之处。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"dukou",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -480);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
