// Room: /d/luoyang/tongtuo.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create()
{
	set("short",  "铜驼暮雨");
	set("long",  @LONG
“铜驼暮雨”是洛阳八大景的最后一景。城东关外的中通巷，隋、
唐、宋时叫“铜驼陌”，它位于隋唐城的城东北隅。每当暮色茫茫，家
家炊烟袅袅上升，犹如蒙蒙烟雨，纷纷扬扬，这就是人们赞不绝口的“
铜驼暮雨”的由来。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  : __DIR__"xiaoxiang",
		"north" : __DIR__"jingu",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
