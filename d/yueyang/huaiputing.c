// Room: /d/yueyang/huaiputing.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "怀甫亭");
	set("long", @LONG
“怀甫亭”是当年杜甫流落巴陵，贫穷潦倒，还为岳阳留下了《登
岳阳楼》等不朽诗篇(poem)。杜甫后来卒于岳阳。由此拾级西上即是岳
阳楼。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("item_desc", ([
		"poem" : "
                        登岳阳楼
　　
                 　　      　　杜甫

                 昔闻洞庭水，今上岳阳楼。
                 吴楚东南坼，乾坤日夜浮。
                 亲朋无一字，老病有孤舟。
                 戎马关山北，凭轩涕泗流。\n"
	]));
	set("exits", ([
		"east"   : __DIR__"loumen",
		"westup" : __DIR__"yueyanglou1",
	]));
	set("coor/x", -1440);
	set("coor/y", -2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
