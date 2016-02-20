// Room: /yangzhou/baitataji.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","白塔塔基");
	set("long",@LONG
白塔，在莲花桥侧莲性寺内，一称喇嘛塔，仿北京北海喇嘛塔式，
其形如锥，高入云表。塔基建台53级，台上造塔，塔身中空，其外层拾
级而上，加青铜缨络鎏金塔铃，最上簇鎏金顶。每值晴日当空，塔顶金
光四射，与南门外文峰塔遥相对峙，称为邗上巨观。扬州民间有“南门
宝塔北门锥”之说。
    白塔塔基。象征佛教“五十三参”的五十三级塔下筑台，石级平台
南嵌“白塔晴云”石额。
LONG );
	set("exits", ([
		"north" : __DIR__"lianxingsi",
		"up"    : __DIR__"baitafokan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}