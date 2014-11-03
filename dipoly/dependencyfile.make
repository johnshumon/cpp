createplayer.o: createplayer.cc createplayer.hh
dipoly.o: dipoly.cc julkinen/die.hh julkinen/boarddrawer.hh \
 julkinen/initreader.hh julkinen/initexception.hh julkinen/utility.hh \
 julkinen/initexception.hh playerlist.hh player.hh squarelist.hh \
 square.hh julkinen/utility.hh game.hh
game.o: game.cc game.hh julkinen/initreader.hh julkinen/initexception.hh \
 julkinen/utility.hh squarelist.hh square.hh julkinen/utility.hh \
 playerlist.hh player.hh julkinen/boarddrawer.hh julkinen/die.hh
player.o: player.cc player.hh
playerlist.o: playerlist.cc playerlist.hh player.hh createplayer.hh
square.o: square.cc square.hh julkinen/utility.hh julkinen/initreader.hh \
 julkinen/initexception.hh julkinen/utility.hh playerlist.hh player.hh
squarelist.o: squarelist.cc squarelist.hh julkinen/initreader.hh \
 julkinen/initexception.hh julkinen/utility.hh square.hh \
 julkinen/utility.hh playerlist.hh player.hh
