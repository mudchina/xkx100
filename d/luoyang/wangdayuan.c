//  Room:  /d/luoyang/wangdayuan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大院");
	set("long",  @LONG
你走进王家大院，院里栽着几丛老梅，枝干甚是虬劲。院角门内小
庭院内，少不了身在洛阳的标志：几盆挺名贵的牡丹。院子中停了不少
车马，每一匹牲口都是鞍辔鲜明。“金刀王家”在洛阳的声势果是不凡。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"wangdatang",
		"west"   :  __DIR__"wangxiaoyuan",
		"out"    :  __DIR__"wanggate",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}