// Room: /qingcheng/zoulang3.c
// Date: Aug. 10 1998 by Winder

inherit RESTROOM_OUT;
void create()
{
	set("short", "松风西廊");
	set("long", @LONG
这里是松风观中连贯操练场和西厢的走廊，松风观高矗山顶，从走
廊望去，青山鸟寂，幽谷风生，漫天薄雾时时弥散在长林翠竹之间。自
古号称：“青城天下幽”，不妨在此体味。这里南边是客房，北边是厨
房，西边常常关着门的是本派弟子的练功休息室。
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"east"  : __DIR__"caochang",
		"north" : __DIR__"chufang",
		"south" : __DIR__"kefang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -840);
	set("coor/z", 90);
	set("door_name","大门");
	set("door_dir","west");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","门上挂了个牌子：休息中。\n");
	set("no_one_msg",   "门上挂了个牌子：青城弟子休息室。\n");
	set("inside_msg",   "门上挂了个牌子：打扰一次、罚跪三天！\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
