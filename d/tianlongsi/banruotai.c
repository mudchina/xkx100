inherit ROOM;

void create()
{
        set("short", "般若台");
        set("long",@LONG
这是个普通的石台，相传当年佛祖曾降临此台传法。再往南去就是本
寺重地——牟尼堂。江湖中传言天龙寺的镇寺之宝——六脉神剑谱就藏于
此中，但你千万不要打什么主意。
LONG );
	set("exits", ([
		"south" : __DIR__"munitang",
		"north" : __DIR__"doushuai",
	]));
	set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}