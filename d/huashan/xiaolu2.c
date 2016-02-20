// xiaolu2.c
// Last Modified by winder on Aug. 1 2002

inherit RESTROOM_OUT;

void create()
{
	set("short", "小山路");
	set("long", @LONG
这里是华山的一条小山路，地势较为平缓，不似其它地方那么险峻。
你走在这里，四周静悄悄的，你就象走进了一个世外桃源。东面好象有
一扇竹门(men)。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"xiaolu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );
	set("no_clean_up", 0);

	set("coor/x", -840);
	set("coor/y", 210);
	set("coor/z", 120);
	set("door_name","竹门");
	set("door_dir","east");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","门上挂了个牌子：华山小筑\n");
	set("inside_msg",   "门上挂了个牌子：打扰一次、罚跪三天！\n");
	set("no_one_msg",   "门上挂了个牌子：华山派休息室。\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
	setup();
}
