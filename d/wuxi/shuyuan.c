// Room: /d/wuxi/shuyuan.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "东林书院");
	set("long", @LONG
东林书院是无锡最有名的讲堂，这里窗明几净，一尘不染。书院里
聚集了江南一带最有名的学儒和才子。他们大多是一些失意归田的旧官
员，在这里传授平生所学，共议天下形势。书案上摆着几本翻开了的线
装书籍。后面是一个书架(shujia)。讲堂内多嵌着历代楹联石刻，足见
书院历史的悠久。左壁是学规(xuegui)。
LONG );
	set("exits", ([
		"south" : __DIR__"shuyuangate",
	]));
	set("item_desc", ([
		"xuegui" : "
日讲经书三起，日看纲目数页。
通晓时务物理，参读古文诗赋。
读书必须过笔，会课按时蚤完。
夜读仍戒晏起，疑误定要力争。

求学需缴学费五十两
 \n",
	]));
	set("objects", ([
		__DIR__"npc/gu" : 1,
	]));
	set("coor/x", 390);
	set("coor/y", -780);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}