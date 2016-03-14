#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Licensed under the GNU LGPL v2.1 - http://www.gnu.org/licenses/lgpl.html


"""

"""

import logging
import sys
import os
from word2vec import Word2Vec, Sent2Vec, LineSentence

logging.basicConfig(format='%(asctime)s : %(threadName)s : %(levelname)s : %(message)s', level=logging.INFO)
logging.info("running %s" % " ".join(sys.argv))

input_file = 'review_music_train_text.txt'
#model = Word2Vec(LineSentence(input_file), size=100, window=5, sg=1, min_count=5, workers=8)
#model.save(input_file + '.model')
#model.save_word2vec_format(input_file + '.wvec')

sent_file = 'review_music_test_text.txt'
model = Sent2Vec(LineSentence(sent_file), model_file=input_file + '.model')
model.save_sent2vec_format(sent_file + '.svec')


program = os.path.basename(sys.argv[0])
logging.info("finished running %s" % program)