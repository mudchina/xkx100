// Room: /d/songshan/eastpath2.c
// Last Modified by Winder on Jul. 15 2001

inherit RESTROOM_OUT;
void create()
{
	set("short", "东廊");
	set("long", @LONG
这里是环绕池塘的走廊，画阑雕栋，却也美仑美奂。一路走来，脚
底木板响动，别有韵味。嵩岳独立天心，八方天风，只吹得天边云起云
落，满山树浪起伏。
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"south" : __DIR__"eastting",
		"north" : __DIR__"eastwuchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 910);
	set("coor/z", 90);
	set("door_name","门");
	set("door_dir","east");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","门上挂了个牌子：休息室。\n");
	set("no_one_msg",   "门上挂了个牌子：休息室。\n");
	set("inside_msg",   "门上挂了个牌子：打扰一次、罚跪三天！\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
