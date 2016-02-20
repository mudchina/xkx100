// siguoya.c
// Dec.11 1997 by Venus

inherit ROOM;
void create()
{
	set("short", "思过崖");
	set("long", @LONG
这是华山的思过崖。危崖上有个山洞，是华山派历代弟子犯规后囚
禁受罚之所。崖上光秃秃的寸草不生，更无一株树木。这危崖自来自来
相传是玉女发钗上的一颗珍珠，当年华山派的祖师以此危崖为惩罚弟子
之所，主要是此处无草无木，无虫无鸟，受罚的弟子在面壁思过之时，
不致为外物所扰，心有旁骛。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"enter"     : __DIR__"sgyhole1",
		"northdown" : __DIR__"yunupath2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );
	set("coor/x", -860);
	set("coor/y", 160);
	set("coor/z", 130);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/siguo", 1);
	return;
}
