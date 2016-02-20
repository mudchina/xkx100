// Room: /yangzhou/qishi.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","棋室");
	set("long",@LONG
棋室面东三楹，北侧接廊通月观后门，中间内悬尉天池题“棋室”
匾，外中柱悬挂康殷所书楹联(lian)。室内陈列瓷绘屏风一樘，十二片，
红木框，樟木膛。瓷绘青花山水、博古，周饰古钱浮雕，瓷绘精良，装
饰美观，四壁悬挂四条彩绘瓷屏，瓷绘八仙人物，亦为稀有之物。
    室内一樘小靠红木家具海梅为框，樱木为膛，条桌还饰以黄杨木雕
纹饰，做工精美。摆设有“鱼纹音石”，敲击声声似编钟。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : "
        青        紫
        山        褥
        载        传
        酒        杯
        呼        近
        棋        笛
        局        休
\n",
	]));
	set("exits", ([
		"west"  : __DIR__"changchunling",
		"east"  : __DIR__"yueguan",
		"south" : __DIR__"qinshi1",
	]));
	set("objects", ([
		"/d/changan/obj/chess" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 110);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
