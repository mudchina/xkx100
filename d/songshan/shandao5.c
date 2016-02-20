// Room: /d/songshan/shandao5.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "胜观山道");
	set("long", @LONG
你走在嵩山胜观峰山道上，遥望太室，少室两山间有一关口。那就
是轩辕关。站在此处，正可饱览嵩山八景的“轩辕早行”(jing)。
LONG );
	set("item_desc", ([
		"jing" : "
    轩辕关又名“娥岭关”。两崖怪石嵯峨，山势雄伟险要，石塞嶙峋
似剑，道路曲折盘旋，为洛都东南险关要道，是历代兵家必争之地。
    轩辕关因山路曲折旋绕，故名“十八盘”。早晨雾遮山腰，行人来
往其中，由下边向上看，好像神仙腾空驾云一样，故有“轩辕早起上云
端”之说。若站在关口，北视关下，可以看到雾浪翻滚，云烟缭绕，瞬
息万变，气象万千。

    诗人刘生题《轩辕道》诗日：
                    陡仄轩辕道，翠屏列上巅。
                    高峰常疑日，密树不开天。
                    风急摧残叶，关峡锁云烟。
                    早行凭眺望，霭霭白云连。

    轩辕关上的山崖下，喷流着一股清泉，名日：“剑引泉”。传说：
汉高祖刘邦率领大军，攻秦夺潼关，路过这里时，人因马乏，滴水不见，
部下一个急将，在关上写了一首打油诗：
                    峨岭似火口，滴水难以瞅。
                    过此喉冒烟，此道不可走。
    刘邦见到此诗，抬脚将诗抹去，拨剑辟进山崖，结果引出一股泉水，
故名“剑引泉”。\n",
	]));
	set("exits", ([
		"northup"   : __DIR__"chaotian",
		"southwest" : __DIR__"fawangsi",
		"southdown" : __DIR__"tieliang",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 820);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
