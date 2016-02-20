// Room: /yangzhou/daxiongbaodian.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","大雄宝殿");
	set("long",@LONG
宝殿面南三楹，迎面二层檐的屋脊上，立有“大雄宝殿”四字横匾。
屋脊正中嵌宝镜一面，迎面嵌“风调雨顺”四字，背面嵌“国泰民安”
四字。
    大雄宝殿供奉三尊大佛，中为释迦牟尼佛，东为药师琉璃光佛，西
为极乐世界阿弥陀佛，释迦牟尼佛两侧胁侍是他的两大弟子，东立阿难，
西立迦叶。东西两厢为十八罗汉，北厢分坐禅宗六祖。佛坛背后为泥塑
群像海岛，上有观音菩萨脚踩巨鳌立像，观音四周有救八难的塑像。观
音像两旁有善财童子和龙女，整个画面有大小塑像百零六尊。
LONG );
	set("exits", ([
		"east"  : __DIR__"qingkongge",
		"west"  : __DIR__"gulintang",
		"north" : __DIR__"cangjinglou",
		"south" : __DIR__"yongdao",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}