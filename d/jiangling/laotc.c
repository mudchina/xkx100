//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "老通城");
	set("long", @LONG
你一走进来，就闻到一股煎豆皮的香味。这是武汉最有名的小吃店，
喜欢吃豆皮、冻豆腐的客人们散坐各处，一位娇憨可人的年轻女人在忙
乎着。虽说有点闹哄哄的，但闲坐于此，听听江湖掌故，嚼嚼香酥可口
的豆皮，也是一大乐事。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"hzjie2",
	]));
	set("objects", ([
		__DIR__"npc/woman" : 1,
	]));
	set("coor/x", -1510);
	set("coor/y", -2110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}