// Room: /d/luoyang/baima1.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "马寺钟声");
	set("long",  @LONG
这里是白马寺的钟楼。每当月白风清之夜，晨曦初露之时，殿内击
磬撞钟佛诵，钟声悠扬飘荡，远闻数里，听之使人心旷神怡。到明代，
寺内有口大铁钟，重约五千余斤，钟声特别洪亮。据传这口钟与洛阳东
大街钟楼上的一口钟音律一致，可以共鸣。人们往往在听到白马寺钟声
的同时，紧接着洛阳城钟楼上的钟也响了，民间流传着“东边撞钟西边
响，西边撞钟东边鸣”的佳话。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"baimasi",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
