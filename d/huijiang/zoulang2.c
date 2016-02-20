// Room: /d/huijiang/zoulang2.c
// Last Modified by winder on Sep. 12 2001

inherit RESTROOM_OUT;

void create()
{
	set("short", "走廊");
	set("long",@LONG
你走在一条长长的走廊上，四周没有一个人，你的脚步声传得很远，
两旁池塘里的残荷上停了几只呱呱乱叫的青蛙，阵阵轻风吹来，令人欲
醉。南边似乎有一扇门。
LONG );
	set("outdoors", "huijiang");	
	set("exits", ([
		"west"     : __DIR__"yixiangting",
		"northup"  : __DIR__"zongduo",
		"eastdown" : __DIR__"zoulang1" ,
	]));
	set("no_clean_up", 0);
	set("coor/x", -50070);
	set("coor/y", 9140);
	set("coor/z", 10);
	set("door_name","门");
	set("door_dir","south");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","门上挂了个牌子：休息室。\n");
	set("no_one_msg",   "门上挂了个牌子：休息室。\n");
	set("inside_msg",   "门上挂了个牌子：打扰一次、罚跪三天！\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
