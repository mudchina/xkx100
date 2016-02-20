// fake_map.c

inherit ITEM;

void create()
{
	set_name("高昌迷宫地图", ({ "map", "ditu" }));
	set_weight(200);
	set("unit", "张");
	set("long", "这是一张丝织高昌迷宫地图，高昌迷宫危险无比。
据说，须按：东，东，南，东，北，北，西，东，南，
方可进入。\n不过这副图好象被抽走几条丝线......\n");
	set("value", 5);
	set("material", "silk");
}

