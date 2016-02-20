//  Room:  /d/lanzhou/baiyun.c

inherit  ROOM;

void  create  ()
{
	set("short",  "白云观");
	set("long",  @LONG
一座山门巍然屹立，下开三个拱形大门，气势雄伟。门额上镶砖雕
牌匾，上书蓝底金色三个大字------白云观。门前两侧左右巨槐掩映，
实为道家修身养性的绝佳去处。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"street1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -9280);
	set("coor/y", 2710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}