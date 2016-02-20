inherit RESTROOM_OUT;

void create()
{
	set("short", "思过室");
	set("long", @LONG
这是桃花岛上供本门弟子闭门思过的地方。屋里仅仅放着一张床，
显得空荡荡的。四面则是光秃秃的墙壁，看上去黑黝黝的，原来却是铁
筑的。靠门的地方有一小洞，洞边放着一只碗。往西是一间不起眼的小
屋，门上挂了个牌子「桃花轩」。
LONG );
	set("exits", ([
		"south"  : __DIR__"liangongfang",
	]));
	set("objects", ([
		__DIR__"npc/mei" : 1,
	]) );	
//	set("no_clean_up", 0);
	set("coor/x", 8980);
	set("coor/y", -2990);
	set("coor/z", 0);
	set("door_name","门");
	set("door_dir","west");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","门上挂了个牌子：桃花轩。\n");
	set("inside_msg",   "门上挂了个牌子：打扰一次、罚跪三天！\n");
	set("no_one_msg",   "门上挂了个牌子：桃花岛弟子休息室。\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
