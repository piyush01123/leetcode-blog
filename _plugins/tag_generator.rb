Jekyll::Hooks.register :posts, :post_write do |post|
    tags = post['tags'].reject { |t| t.empty? }
    tags.each do |tag|
      generate_tag_file(tag)
    end
  end
  
  def generate_tag_file(tag)
    # generate tag file
    File.open("_tag/#{tag}.md", "wb") do |file|
      file << "---\nlayout: tag\ntag-name: #{tag}\n---\n"
    end
  end
