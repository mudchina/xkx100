// Room: /d/luoyang/luoshenmiao.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "洛神庙");
	set("long",  @LONG
在神话传说中，江河湖泊都是有神类居住管理的，譬如四海中的龙
王兄弟们。据说，掌管洛河水印的“洛神”是位仙女，以前，人们都认
为她是伏羲氏的女儿宓妃。进得庙来，面对洛神塑像，恐怕马上涌上心
头的便是曹子建得文字吧。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northeast" : __DIR__"southroad",
	]));
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
