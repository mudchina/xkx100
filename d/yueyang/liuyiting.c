// Room: /d/yueyang/liuyijing.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "柳毅传书亭");
	set("long", @LONG
柳毅传书后，洞庭龙王为了报答柳毅毅救女之恩，要将三公主嫁给
柳毅，柳毅认为救人于危难之中乃人之本份，不可因此而为谋利，婉言
谢绝了。柳毅出宫后，倾慕柳毅的龙女扮成渔家姑娘，与柳毅结成夫妻，
婚后才道破实情，与柳毅返回洞庭水府，柳毅被封王为洞庭王。
    人们为了纪念柳毅传书，改桔井为柳毅井，并在井旁建有柳毅传书
亭(ting)。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("item_desc", ([
		"ting" : "
      牧羊坡上遇青娥，为托传书意若何？
      坐望直穷寻桔树，莫道遥隔洞庭波。
 　 　龙宫弟子缄方启，尘世朗君祸已多。
  　　留得旧时迹井在，井泉香冽出川阿。\n"
	]));
	set("exits", ([
		"west" : __DIR__"liuyijing",
	]));
	set("coor/x", -1680);
	set("coor/y", 2310);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
