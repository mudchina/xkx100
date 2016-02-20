// Room: /d/xingxiu/riyuedong.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "日月洞");
	set("long", @LONG
这里是星宿派总舵所在地日月洞。洞内灯火通明，正中一把虎皮椅
上端坐着星宿派掌门人丁春秋。两边各站列着数十位星宿派弟子，不断
有各派人士走进来献(xian)上各种宝物。在一片歌功颂德之声中，洋洋
盈耳，丝竹箫管也跟着吹奏。丁春秋每听到得意之时，禁不住挥动手中
的羽扇，捋着白须，眯起了双眼，薰薰然，飘飘然，有如饱醉醇酒。
    洞壁上装饰着虎皮、鹿头、雕羽，及一些字画(zihua)。 洞两侧竖
立兵器架，上面排列的大多是各种棍棒。
LONG );
	set("exits", ([
		"south" : __DIR__"riyuedong1",
	]));

	set("item_desc", ([
		"zihua" : "都是些吹捧星宿老仙的诗词和他的画像。\n

※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　※※※※
※※※※　古　威　德　星　※※※※
※※※※　今　震　配　宿　※※※※
※※※※　无　寰　天　老　※※※※
※※※※　比　宇　地　仙　※※※※
※※※※　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※
"
	]) );

	set("objects", ([
		CLASS_D("xingxiu")+"/ding" : 1,
		__DIR__"npc/obj/tiegun" : 1,
		__DIR__"npc/obj/huoyan" : 1,
	]) );
//	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 20400);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
