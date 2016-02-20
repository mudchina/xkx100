// Room: /d/taishan/dongling.c
// Last Modified by Winder on Aug. 25 2001

inherit RESTROOM_OUT;

void create()
{
	set("short", "东灵殿");
	set("long", @LONG
这里是泰山派的根本重地。殿内布置肃穆，正中神案上泰山派开派
祖师东灵道长的牌位和画像。神案上香炉里插着三柱清香，香烟袅袅上
升，散发着一股檀香味。
    后殿现在是泰山派弟子练功的休息间。
LONG );
	set("exits", ([
		"east"    : __DIR__"riguanroad2",
		"westup"  : __DIR__"riguanroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 770);
	set("coor/z", 190);
	set("door_name","殿门");
	set("door_dir","north");
	set("restroom",__DIR__"dongling1");
	set("open_door_msg","门上挂了个牌子：休息室。\n");
	set("inside_msg",   "门上挂了个牌子：打扰一次、罚跪三天！\n");
	set("no_one_msg",   "门上挂了个牌子：休息室。\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
