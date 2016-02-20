//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "棺材铺");
	set ("long", @LONG
这是一家卖棺材的店铺，门面不大，却有个后院用来摆放做好的棺
材。掌柜的站在门口，似笑非笑地盯着来往的客人。兵荒马乱的年头，
这死人的生意还挺兴隆。一缕光线透过柜台后的小门，照在一副刚漆好
的棺材板上，亮闪闪地有些晃眼。
LONG);
	set("exits", ([ 
		"east" : __DIR__"xijie2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
